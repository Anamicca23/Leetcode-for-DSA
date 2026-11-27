class Solution:
    def myAtoi(self, s: str) -> int:
        phase = 0
        result = 0
        sign = 1
        numbers = '0123456789'
        limit = 2**31 - 1

        for element in s:
            if element == ' ':
                if phase != 0:
                    return result * sign
            
            elif element in "+-" and phase == 0:
                sign = -1 if element == '-' else 1
                limit = 2**31 if sign == -1 else 2**31 - 1
                phase = 1
            
            elif element in numbers:
                phase = 2
                element_value = numbers.index(element)
                if result > (limit - element_value) // 10:
                    return limit * sign

                result = result * 10 + element_value

            else:
                return result * sign
        
        return result * sign

        

            


            

                