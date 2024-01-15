class Solution {
public:
    bool isUnique(string astr)
    {
        if (astr.size() > 26) return fakse;//判断字符串长度是否大于26个英文字母,如果大于,代表重复
        int bitmap = 0;//设置位图
        for (auto ch : astr)
        {
            int i = ch - 'a';//定位字符的位置
            if (((bitmap >> 1) & 1) == 1) return false;//如果为1,代表重复.
            bitmap |= 1 << i;//当不满足循环的时候,代表未重复,让bitmap对应的i位变为1
        }
        return true;
    }
};
//2 给一个正数n，确定它的二进制表示中的第x位是0还是1;
//int x = (n >> x) & 1;
// 
//3 将一个n的二进制表示的第x位修改成1
// nl= (1 << x) ;
