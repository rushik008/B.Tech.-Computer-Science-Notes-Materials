a = [10, 20, 30, 40, 50, 11, 12, 13, 14, 15]
print(a)

print("Sorting the list\n")
a.sort()
print(a)

print("Removing last element from sorted list\n")
a.pop()
print(a)

print("appending element: 20 at last\n")
a.append(20)
print(a)

print("appending element:120, 200 at last\n")
a.extend([120, 200])
print(a)

b = {
    "Name": "Rushik",
    "Age": 20,
    "Semester": 4
}
print(b)

print("Upadte semester to fifth\n")
b.update({"Semester": 5})
print(b)
print("Adding city : Anand to dictionary\n")
b["city"] = "Anand"
print("Printing value of city " + b["city"])

print("Removing city from dictionary\n")
b.popitem()
print(b)
