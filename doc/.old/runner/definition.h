/**
 * @file definition.h(vm/runner)
 * @author senyun.yao
 * @brief 
 * @version 0.1
 * @date 2021-11-15
 * 
 * @copyright aitianyu.cn Copyright (c) 2021
 * 
 */

#ifndef __DTY_NATIVE_VM_RUNNER_DEFINITION_H__
#define __DTY_NATIVE_VM_RUNNER_DEFINITION_H__

#include "../utilize.h"

namespace dty
{
    namespace vm
    {
        namespace run
        {
            enum ProcessDirect
            {
                FORWARD,
                BACKWARD
            };

            enum CalculationDirect
            {
                ORDOR,
                REVERS
            };

            struct CalculationMember
            {
                byte __POINTER__ _Data;
                byte __VARIABLE__ _Size;
            };

            struct CalculationResult
            {
                bool __VARIABLE__ _Status;
                byte __POINTER__  _Result;
                byte __VARIABLE__ _Size;
            };
            

            _interface IFlagRegister
            {

            };

            _interface IFloatFlagRegister
            {

            };

            _interface IThreadRunner
            {

            };

            _interface IExecution
            {

            };

            _interface IInvokeStack
            {

            };
        }
    }
}

#endif // !__DTY_NATIVE_VM_RUNNER_DEFINITION_H__