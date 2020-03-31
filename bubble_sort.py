# def sort(list):
#     tmp = 0
#     for (int i = 0; i < list.size(); i++) {
#         for (int j = i + 1; j < list.size(); j++) {
#             if (list[j] < list[i]) {
#                 tmp = list[i];
#                 list[i] = list[j];
#                 list[j] = tmp;
#             }
#         }
#     }
# }

def sort(list):
    tmp = 0
    for i in range(0, len(list)):
        for j in range(i + 1, len(list)):
            if list[j] < list[i]:
                tmp = list[i]
                list[i] = list[j]
                list[j] = tmp

list = [4, 17, 7, 14, 18, 12, 3, 16, 10, 4, 4, 12]
print("list before sorting: ", list)
sort(list)
print("list after sorting: ", list)