class Solution2:
    # Function to sort an array using quick sort algorithm.
    def quickSort(self, arr, low, high):
        if low >= high:
            return

        part_index = self.partition(arr, low, high)

        self.quickSort(arr, low, part_index - 1)
        self.quickSort(arr, part_index + 1, high)

    # Function that takes first element as pivot, places the pivot element at
    # its correct position in sorted array, and places all smaller elements
    # to left of pivot and all greater elements to right of pivot.
    def partition(self, arr, low, high):
        pivot = arr[low]
        i = low
        j = high

        while i < j:
            while i <= high - 1 and arr[i] <= pivot:
                i += 1

            while j >= low + 1 and arr[j] > pivot:
                j -= 1

            if i < j:
                # swap arr[i] and arr[j]
                arr[i], arr[j] = arr[j], arr[i]

        # swap arr[j] and pivot
        arr[low], arr[j] = arr[j], arr[low]

        return j
