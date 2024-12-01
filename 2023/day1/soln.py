# Note: Recently watched LowLevelLearning's video on this problem to get an idea of what
# Advent of Code is like; all other problems are, to my awareness, my own solution 
string_to_int: dict[str, int] = {
    "one" : 1,
    "two" : 2,
    "three" : 3,
    "four" : 4,
    "five" : 5,
    "six" : 6,
    "seven" : 7,
    "eight" : 8,
    "nine" : 9,
}

def main():
    with open("input", "r") as file:
        sum: int = 0
        for line in file:
            print(line, end="")
            leftmost: int = -1
            rightmost: int = -1
            for i in range(0, len(line)):
                match: int = get_match(line, i)
                if match != -1:
                    if leftmost == -1:
                        leftmost = match
                    rightmost = match
            print(f'{leftmost}{rightmost}')
            sum += leftmost * 10 + rightmost

        print(f'Solution: {sum}')

def get_match(line: str, start: int) -> int:
    substr: str = line[start:]
    if substr[0].isdigit():
        return int(substr[0])

    num_strs = list(string_to_int)
    
    for num_str in num_strs:
        if substr.startswith(num_str):
            return string_to_int[num_str]

    return -1

main()

