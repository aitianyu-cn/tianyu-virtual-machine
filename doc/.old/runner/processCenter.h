/**
 * @file processCenter.h(vm/runner)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-11-15
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_VM_RUNNER_PROCESSCENTER_H__
#define __DTY_NATIVE_VM_RUNNER_PROCESSCENTER_H__

#include "./definition.h"

namespace dty
{
    namespace vm
    {
        namespace run
        {
            class ALU final
            {
                /*
                 * notes:
                 * use bytes array to implement data input and return value.
                 * every calculation need transmit three type parameters.
                 * 1. calculate member(s){bytes array}
                 * 2. an data structure provide some status of calculate result{interface}
                 *      e.g. [zero flag][sign flag][parity flag]...
                 * 3. thread runner interface instance{interface}.
                 *
                 * every calculation need to return two result.
                 * 1. calculate result{boolean}, success if return true or failed return false.
                 * 2. calculate result{bytes array}
                */

#pragma region arithmetic group
                __PUB__ static CalculationResult __VARIABLE__ Add
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Sub
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Mul
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance,
                    CalculationMember*  highOrder
                );
                __PUB__ static CalculationResult __VARIABLE__ Div
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance,
                    CalculationMember*  remainder
                );

                __PUB__ static CalculationResult __VARIABLE__ UAdd
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ USub
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ UMul
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance,
                    CalculationMember*  highOrder
                );
                __PUB__ static CalculationResult __VARIABLE__ UDiv
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance,
                    CalculationMember*  remainder
                );
#pragma endregion

#pragma region logic group
                __PUB__ static CalculationResult __VARIABLE__ And
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Or
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Xor
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Not
                (
                    CalculationMember   member,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Neg
                (
                    CalculationMember   member,
                    IFlagRegister&      flags,
                    IThreadRunner&      runnerInstance
                );
#pragma endregion
            };

            class FPU final
            {
#pragma region float calculation
                __PUB__ static CalculationResult __VARIABLE__ Add
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFloatFlagRegister& flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Sub
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFloatFlagRegister& flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Mul
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFloatFlagRegister& flags,
                    IThreadRunner&      runnerInstance
                );
                __PUB__ static CalculationResult __VARIABLE__ Div
                (
                    CalculationMember   memberA,
                    CalculationMember   memberB,
                    IFloatFlagRegister& flags,
                    IThreadRunner&      runnerInstance
                );
#pragma endregion

#pragma region float conversion
                __PUB__ static CalculationResult __VARIABLE__ F2I(CalculationMember member);
                __PUB__ static CalculationResult __VARIABLE__ I2F(CalculationMember member);
                __PUB__ static CalculationResult __VARIABLE__ D2I(CalculationMember member);
                __PUB__ static CalculationResult __VARIABLE__ I2D(CalculationMember member);

                __PUB__ static CalculationResult __VARIABLE__ F2D(CalculationMember member);
                __PUB__ static CalculationResult __VARIABLE__ D2F(CalculationMember member);
#pragma endregion
            };

            class Control final
            {
                /*
                 * notes:
                 * control is a exection controller to execute condition, jump statements.
                 * every control function need at least:
                 * 1. status of data{IFlagRegister}
                 * 2. thread runner interface instance{IThreadRunner}
                 * 3. exection object{IExecution}
                 * 4. progress invoke stack{IInvokeStack}
                */

#pragma region unconditional jump
                __PUB__ static void __VARIABLE__ Jump
                (
                    byte            jumpStep,
                    ProcessDirect   processDirect,
                    IFlagRegister&  flags,
                    IThreadRunner&  runnerInstance,
                    IExecution&     execution,
                    IInvokeStack&   invokeStack
                );
                __PUB__ static void __VARIABLE__ Jump
                (
                    byte                jumpStep,
                    ProcessDirect       processDirect,
                    IFloatFlagRegister& flags,
                    IThreadRunner&      runnerInstance,
                    IExecution&         execution,
                    IInvokeStack&       invokeStack
                );
                __PUB__ static void __VARIABLE__ JumpFar
                (
                    uint64          jumpStep,
                    ProcessDirect   processDirect,
                    IFlagRegister&  flags,
                    IThreadRunner&  runnerInstance,
                    IExecution&     execution,
                    IInvokeStack&   invokeStack
                );
                __PUB__ static void __VARIABLE__ JumpFar
                (
                    uint64              jumpStep,
                    ProcessDirect       processDirect,
                    IFloatFlagRegister& flags,
                    IThreadRunner&      runnerInstance,
                    IExecution&         execution,
                    IInvokeStack&       invokeStack
                );
#pragma endregion

#pragma region function call
                __PUB__ static void __VARIABLE__ Call
                (
                    uint64          jumpStep,
                    IFlagRegister&  flags,
                    IThreadRunner&  runnerInstance,
                    IExecution&     execution,
                    IInvokeStack&   invokeStack
                );
#pragma endregion
            };
        }
    }
}

#endif // !__DTY_NATIVE_VM_RUNNER_PROCESSCENTER_H__