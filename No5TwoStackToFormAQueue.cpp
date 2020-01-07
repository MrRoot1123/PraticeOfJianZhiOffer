class Solution
{
public:
    void push(int node) {
        stack1.push(node);
        return;
    }

    int pop() {
        int popResult = 0;
        if (stack2.empty()){
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        popResult = stack2.top();
        stack2.pop();
        return popResult;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};