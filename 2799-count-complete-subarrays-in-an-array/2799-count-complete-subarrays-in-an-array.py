class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        total_unique = len(set(nums))
        count = 0
        left = 0
        freq = {}

        for right in range(len(nums)):
            # Добавляем элемент в словарь
            if nums[right] in freq.keys():
                freq[nums[right]] = freq[nums[right]] + 1
            else:
                freq[nums[right]] = 1
                
            # Сужаем окно, если оно содержит все уникальные элементы
            while len(freq) == total_unique:
                count += len(nums) - right  # Все подмассивы, начинающиеся с left
                freq[nums[left]] -= 1
                if freq[nums[left]] == 0:
                    del freq[nums[left]]  # Удаляем элемент, если его количество стало 0
                left += 1

        return count