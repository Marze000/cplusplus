def coinChange(coins, amount):
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
            else:
                break
        dp[i] = min_val+1
    return dp[amount] if dp[amount] <= amount else -1


if __name__ == "__main__":
    coins = [1, 2, 5]
    amount = 11
    a = coinChange(coins, amount)
    print(a)
