gcd = lambda a, b : b and gcd(b,a%b) or a
T = int(raw_input())
for t in range(T):
    var = raw_input()
    n, l = [long(x) for x in var.split()]
    values = [long(x) for x in raw_input().split()]
    primes_prelim = []
    for i in range(l-1):
        p = gcd(values[i],values[i+1])
        if p != values[i] and p not in primes_prelim:
            primes_prelim += [p]
    for i in primes_prelim:
        p0 = values[0]/i
        if values[0]%i == 0 and p0 not in primes_prelim:
            primes_prelim += [p0]
        pl = values[l-1]/i
        if values[l-1]%i == 0 and pl not in primes_prelim:
            primes_prelim += [pl]
    for i in primes_prelim:
        p0 = values[0]/i
        if values[0]%i == 0 and p0 not in primes_prelim:
            primes_prelim += [p0]
        pl = values[l-1]/i
        if values[l-1]%i == 0 and pl not in primes_prelim:
            primes_prelim += [pl]
    primes = sorted(primes_prelim)
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    table = {primes[i]: alphabet[i] for i in range(26)}
    code = []
    for i in primes:
        if values[0]%i == 0 and values[1]%i != 0:
            code += [i]
    for i in range(l):
        code += [values[i]/code[i]]
    sol = ""
    for i in code:
        sol += table[i]
    print "Case #" + str(t+1) + ": " + sol
