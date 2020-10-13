#include <node_api.h>
#include <stdio.h>
//hello world native function
napi_value helloWorld(napi_env env, napi_callback_info info)
{
    printf("Hello World Program for my thesis, ----\n");
    return NULL;
}

napi_value Init(napi_env env, napi_value exports)
{
    napi_status status;
    napi_value result;  //representing the JS function object for the newly created function.& represents a variable address
    //The native function 'helloWorld' should be called when this function object is invoked.
  status =   napi_create_function(env, NULL, 0, helloWorld, NULL, &result);
    if (status != napi_ok)
        return NULL;

    status = napi_set_named_property(env, exports, "helloWorld", result);
    if (status != napi_ok)
        return NULL;

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)