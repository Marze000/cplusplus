def coinChange(self, coins: List[int], amount: int) -> int:
    if not coins:
        return 0
    dp = [0]*(amount+1)
    coins.sort()
    for i in range(1, amount+1):
        if i in coins:
            dp[i] = 1
            continue
        min_val = amount
        for coin in coins:
            if i >= coin:
                min_val = min(min_val, dp[i-coin])
        dp[i] = min_val+1
    if dp[amount] > amount:
        return -1
    else:
        return dp[amount]
