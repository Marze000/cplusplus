def shortestDistance(words, word1, word2):
    res = len(words)
    pos1, pos2 = None, None
    for idx, word in enumerate(words):
        if word == word1:
            pos1 = idx
        elif word == word2:
            pos2 = idx
        if pos1 is not None and pos2 is not None:
            res = min(res, abs(pos1 - pos2))
    return res


if __name__ == "__main__":
    words = ["practice", "makes", "perfect", "coding", "makes"]
    word1 = "makes"
    word2 = "coding"
    a = shortestDistance(words, word1, word2)
    print(a)
