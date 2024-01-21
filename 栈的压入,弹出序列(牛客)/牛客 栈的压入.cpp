class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV)
    {
        stack<int> st;
        int pushi = 0, popi = 0;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi++]);
            while (!st.empty() && st.top() == popV[popi])
            {
                st.pop();
                ++popi;
            }
        }
        return popi == popV.size();
    }
};