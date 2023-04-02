import hashlib 

def hash_starts_with_n_zeros(hash, n):
    for i in range(n):
        if (hash[i] != '0'):
            return False
    return True

def find_first_keys(key):
    hash = "11111"
    x = 0
    while (not (hash_starts_with_n_zeros(hash, 5))):
        hash = (hashlib.md5((key + str(x)).encode())).hexdigest()
        x += 1

    hash2 = "11111"
    x2 = 0
    while (not (hash_starts_with_n_zeros(hash2, 6))):
        hash2 = (hashlib.md5((key + str(x2)).encode())).hexdigest()
        x2 += 1
    return x - 1, x2 - 1

key = "iwrupvqb"
x1, x2 = find_first_keys(key)
print("First key that hashes to a string with 5 leading zeros = {}".format(x1))
print("First key that hashes to a string with 6 leading zeros = {}".format(x2))