class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
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