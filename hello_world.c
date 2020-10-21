#include <node_api.h>
#include <stdio.h>
//hello world native function
int twice(int x)
{
    printf("inside the body of napi_llcan function");
    return 2*x;
}

napi_value helloWorld(napi_env env, napi_callback_info info)
{
    napi_value cb = args[0];
    printf("line number 13 helloWorld function called");
    int number = twice(numberValue);
    printf("the number is : %d\n", number);
    printf("the &number is : %d\n", &number);
    printf("the numberValue is : %d\n", numberValue);
    napi_status status;
    size_t argc = 1;
    napi_value argv[1];
    status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL); // for call back funtion in index.js

    status = napi_get_value_int32(env, argv[0], &number);
    napi_value canID;
    status = napi_create_int32(env, number, &canID);
    return canID;

}

napi_value Init(napi_env env, napi_value exports)
{
    napi_status status;
    napi_value result; //representing the JS function object for the newly created function.& represents a variable address
                       //The native function 'helloWorld' should be called when this function object is invoked.
    status = napi_create_function(env, NULL, 0, helloWorld, NULL, &result);
    if (status != napi_ok)
        return NULL;

    status = napi_set_named_property(env, exports, "helloWorld", result);
    if (status != napi_ok)
        return NULL;

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)
