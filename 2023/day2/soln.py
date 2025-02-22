bag: dict[str, int] = {
    "red": 12,
    "green": 13,
    "blue": 14,
}


def main():
    with open("input", "r") as file:
        game_id: int = 1
        id_sum: int = 0
        power_sum: int = 0
        for line in file:
            draw_rec: str = line.split(": ")[1]
            min_possible: dict[str, int] = get_min_possible(draw_rec)
            if game_is_possible(min_possible):
                id_sum += game_id
            power_sum += (
                min_possible["red"] * min_possible["green"] * min_possible["blue"]
            )
            game_id += 1
        print(f"id_sum = {id_sum}")
        print(f"power_sum = {power_sum}")


def get_min_possible(draw_rec: str) -> dict[str, int]:
    min_possible: dict[str, int] = {
        "red": 0,
        "green": 0,
        "blue": 0,
    }

    split_rec: list[str] = draw_rec.split(" ")

    i: int = 0
    while i < len(split_rec):
        num = int(split_rec[i])
        color = split_rec[i + 1].strip(",;\n")

        if num > min_possible[color]:
            min_possible[color] = num

        i += 2

    return min_possible


def game_is_possible(min_possible: dict[str, int]) -> bool:
    return (
        min_possible["red"] <= bag["red"]
        and min_possible["green"] <= bag["green"]
        and min_possible["blue"] <= bag["blue"]
    )


main()
