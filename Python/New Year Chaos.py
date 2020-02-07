def serialize(number):
    return number ** 3014 % 10000


def check(_base, _target):
    _base = list(map(int, _base.split(',')))
    _target = list(map(int, _target.split(',')))
    result = [0 for _ in range(len(_target))]
    for i in range(len(_target)):
        if _target[i] - i > 3:
            print("Invalid")
        else:
            print("Valid")
            result[_target[i]-1] = _target[i] - i - 1
    print(_base, _target, result)


if __name__ == '__main__':
    # base = input("Enter initial string:\t")
    # target = input("Enter test string:\t")
    # check(base, target)
    check("1,2,3,4,5,6", "3,4,2,6,1,5")
