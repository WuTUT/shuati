1. 滚动数组优化
    ```
        j递增
      1 2 3 4
    1 o 
    2   o * x i递减
    3     * * 
    4       o
    ```
    用*来更新x 可以f[2][N]优化f[N][N]
    枚举顺序依更新顺序
    POJ1159：添加最少字符构成回文序列
    int p= i&1
    f[终止的i&1][N]
    ```cpp 
    for (int i = n; i >= 1; i--)
    {
        int p = i & 1;
        memset(f[p], 0, sizeof f[p]);
        for (int j = i + 1; j <= n; j++)
        {
            if (s[i] == s[j])
                f[p][j] = f[p ^ 1][j - 1];
            else
                f[p][j] = min(f[p ^ 1][j], f[p][j - 1]) + 1;
        }
    }
    ```
    i%3 (i+1)%3 : i-2  (i+2)%3 : i-1

2. 背包
   求$max_{select(i)} \Sigma_{i=1}a_i$
   约束形如<font color=#0099ff size = 4>$$\frac{\Sigma_{i=1}^{N}a_i}{\Sigma_{i=1}^{N}b_i}=k $$</font>等价于$\Sigma_{i=1}^{N}(a_i-kb_i)=0 $
   体积$V_i = a_i-kb_i $ 价值为$a_i$ 即背包为0时的最大价值的背包问题 
