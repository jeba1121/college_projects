package edu.colorado.csci3155.project1


sealed trait StackMachineInstruction
case object AddI extends StackMachineInstruction
case object SubI extends StackMachineInstruction
case object MultI extends StackMachineInstruction
case object DivI extends StackMachineInstruction
case object ExpI extends StackMachineInstruction
case object LogI extends StackMachineInstruction
case object SinI extends StackMachineInstruction
case object CosI extends StackMachineInstruction
case class PushI(f: Double) extends StackMachineInstruction
case object PopI extends StackMachineInstruction


object StackMachineEmulator {

    /* Function emulateSingleInstruction
        Given a list of doubles to represent a stack and a single instruction of type StackMachineInstruction
        Return a stack that results when the instruction is executed from the stack.
        Make sure you handle the error cases: eg., stack size must be appropriate for the instruction
        being executed. Division by zero, log of a non negative number
        Throw an exception or assertion violation when error happens.

     */
    def emulateSingleInstruction(stack: List[Double], ins: StackMachineInstruction): List[Double] = ins match{
        case PushI(f) => stack:+ f
        case PopI => if(stack.isEmpty){
            throw new IllegalArgumentException ("Stack is Empty")
        } else{
            stack.filter(_ != stack.last)
        }
        case AddI => if(stack.size < 2){
            throw new IllegalArgumentException("Stack cannot add")
        }else{
            val y = stack.takeRight(2)
            val ans = y(0) + y(1)
            val newList = stack.filter(num => num!= y(0) && num!= y(1))
            newList:+ ans
        }
        case SubI => if(stack.size < 2){
            throw new IllegalArgumentException("Stack cannot sub")
        }else{
            val y: List[Double] = stack.takeRight(2)
            val v1 = y(1)
            val v2 = y(0)
            val ans = v2-v1
            val newList = stack.filter(num=> num!= y(0) && num!= y(1))
            newList:+ ans
        }
        case MultI => if(stack.size < 2){
            throw new IllegalArgumentException("Stack cannot mult")
        }else{
            val y: List[Double] = stack.takeRight(2)
            val ans = y(0) * y(1)
            val newList = stack.filter(num => num!=y(0) && num!=y(1))
            newList:+ ans
        }
        case DivI => if(stack.size<0){
            throw new IllegalArgumentException("Stack cannot Div")
        }else{
            val y: List[Double] = stack.takeRight(2)
            val v1 = y(1)
            val v2 = y(0)
            if(v1 == 0){
                throw new IllegalArgumentException("Cannot Div By 0")
            }
            val ans = v2/v1
            val newList = stack.filter(num => num!=y(0) && num!=y(1))
            newList:+ ans
        }
        case LogI => if(stack.isEmpty){
            throw new IllegalArgumentException("Dude it's not gonna work cause its too small")
        }else{
            val y: List[Double] = stack.takeRight(1)
            if(y(0) < 0 ){
                throw new IllegalArgumentException("0 is my enemy")
            }else {
                val ans = math.log(y(0))
                val newList = stack.filter(num => num != y(0))
                newList:+ ans
            }
        }
        case ExpI => if(stack.isEmpty){
            throw new IllegalArgumentException("Empty. error")
        }else{
            val y: List[Double] = stack.takeRight(1)
            val ans = math.exp(y(0))
            val newList = stack.filter(num => num!= y(0))
            newList:+ ans
        }
        case CosI => if(stack.isEmpty){
            throw new IllegalArgumentException(">:C too small")
        }else{
            val y: List[Double] = stack.takeRight(1)
            val ans = math.cos(y(0))
            val newList = stack.filter(num => num!= y(0))
            newList:+ ans
        }
        case SinI => if(stack.isEmpty){
            throw new IllegalArgumentException(":c too small")
        }else{
            val y: List[Double] = stack.takeRight(1)
            val ans = math.sin(y(0))
            val newList = stack.filter(num => num!= y(0))
            newList:+ ans
        }
    }


    /* Function emulateStackMachine
       Execute the list of instructions provided as inputs using the
       emulateSingleInstruction function.
       Use foldLeft over list of instruction rather than a for loop if you can.
       Return value must be a double that is the top of the stack after all instructions
       are executed.
     */
    def emulateStackMachine(instructionList: List[StackMachineInstruction]): Double = {
        val x = instructionList.foldLeft(List.empty[Double])((stack:List[Double], ins:StackMachineInstruction) => {
            emulateSingleInstruction(stack, ins)
        })
        x.last
    }
}