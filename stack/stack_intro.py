#stack 

#creating a stack
def create_stack():
    stack = []
    return stack

#checking if empty
def stack_isempty(stack):
    return(len(stack) == 0)

#Push function

def stack_push(stack, item):
    stack.append(item)
    print("pushed item" , item)

#pop function
def stack_pop(stack):
    if(stack_isempty(stack)):
        print("Empty stack")
        return
    
    stack.pop()

if __name__ == '__main__':
    stack = create_stack()
    
    for i in range(1,8):
        stack_push(stack , i)
        i+=1
    stack_pop(stack)
    stack_pop(stack)
    print(stack)



