def solution(numbers):
    answer = []
    bit_arr = [2**i for i in range(51)]
    bit_arr.reverse()
    for number in numbers:
        temp = number
        save_number = number
        while True:
            temp = temp + 1
            save_temp = temp
            number = save_number
            cnt = 0
            for bit_num in bit_arr:
                tb = 0
                if temp >= bit_num and number >= bit_num:
                    temp -= bit_num
                    number -= bit_num
                elif temp >= bit_num and number < bit_num:
                    temp -= bit_num
                    cnt += 1
                elif temp < bit_num and number >= bit_num:
                    number -= bit_num
                    cnt += 1
                if cnt >= 3:
                    break

            temp = save_temp

            if cnt <= 2:
                answer.append(temp)
                break
    return answer


print(solution([2, 7]))

#[2**i for i in range(10)]
