/*******************************************************************************
 * Copyright 2013-2014 Aerospike, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include <node.h>


/*******************************************************************************
 *  FUNCTIONS
 ******************************************************************************/
/**
 *  Setup an asynchronous invocation of a function.
 */
Handle<Value> async_invoke(
    ResolveArgs(args), 
    void *  (* prepare)(ResolveArgs(args)), 
    void    (* execute)(uv_work_t * req),
    void    (* respond)(uv_work_t * req, int status)
    );

void async_init( uv_async_t * async, void (*async_callback)(ResolveAsyncCallbackArgs));

void async_send( uv_async_t * async);

void async_close(uv_async_t* async);

void uv_initialize_loop();

void uv_finish_loop_execution();
