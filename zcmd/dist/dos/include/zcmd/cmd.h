
#ifndef ZCMD_CMD_HEADER
#define ZCMD_CMD_HEADER
#define CMD_MAX 256

#ifndef NULL
#define NULL 0
#endif

typedef int (*cmdfun) (int argc,char** argv);
struct t_cmdinfo {
        const char* name;
        const char* ver;
        const char* desc;
        const char* usage;
        const char* option;
        cmdfun call;
};
typedef struct t_cmdinfo CMDINFO;

   int cmd_register(const char* name,const char* ver, const char* desc, const char* usage, const char* option, cmdfun call);
   int cmd_idx(const char* cmdname) ;
   int cmd_exec(int idx,int argc,char** argv);
   int cmd_list(void);
   CMDINFO *cmd_info(int idx);
   int cmd_init(void);


    #define CMD_GET_MAIN(name) main_ ## name
    #define CMD_GET_REGISTER(name) register_ ## name


   #define REGISTER_CMD(CMD) cmd_register( \
                      CMD ## _NAME, CMD ## _VER, \
                      CMD ## _DESC, CMD ## _USAGE, \
                      CMD ## _OPTION, (cmdfun) CMD ## _PROCESS \
                      )
   #define DECLARE_CMD_MAIN(name) \
        int CMD_GET_MAIN(name) (int argc,char** argv)
   #define DECLARE_CMD_REGISTER(name) \
        int CMD_GET_REGISTER(name) (void)

   #define DEFINE_CMD_INFO(NAME,VER,DESC,USAGE,OPTION) \
        extern const char* NAME ## _NAME = # NAME;\
        extern const char* NAME ## _VER = VER;\
        extern const char* NAME ## _DESC = DESC;\
        extern const char* NAME ## _USAGE = USAGE;\
        extern const char* NAME ## _OPTION = OPTION;\
        extern const cmdfun NAME ## _PROCESS = (cmdfun) CMD_GET_MAIN(NAME);\
        DEFINE_CMD_REGISTER(NAME)

   #define DECLARE_CMD(name) \
        DECLARE_CMD_MAIN(name); \
        DECLARE_CMD_REGISTER(name);
    
    #define DEFINE_CMD_REGISTER(name) \
        DECLARE_CMD_REGISTER(name) {\
            return REGISTER_CMD_INFO(name);\
        }
    
   #define REGISTER_CMD_INFO(name) cmd_register( \
                      name ## _NAME, name ## _VER, \
                      name ## _DESC, name ## _USAGE, \
                      name ## _OPTION, (cmdfun) name ## _PROCESS \
                      )
   #define CMD_INIT(name) CMD_GET_REGISTER(name)();

    #define DEFINE_CMD_MAIN(name,argc,argv) \
        int CMD_GET_MAIN(name) (argc,argv)
     

#endif
