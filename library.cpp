#include "redismodule.h"
#include <stdlib.h>

#include "findere/src/libraries/findere/customAMQ.hpp"


class bfAMQ : public customAMQ {};


int HelloworldRand_RedisCommand(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    RedisModule_ReplyWithLongLong(ctx,rand());
    return REDISMODULE_OK;
}


#ifdef __cplusplus
extern "C" {
#endif

int RedisModule_OnLoad(RedisModuleCtx *ctx, RedisModuleString **argv, int argc) {
    if (RedisModule_Init(ctx,"helloworld",1,REDISMODULE_APIVER_1)
    == REDISMODULE_ERR) return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx,"helloworld.rand",
                                  HelloworldRand_RedisCommand, "fast random",
                                  0, 0, 0) == REDISMODULE_ERR)
        return REDISMODULE_ERR;

    return REDISMODULE_OK;
}

#ifdef __cplusplus
}
#endif