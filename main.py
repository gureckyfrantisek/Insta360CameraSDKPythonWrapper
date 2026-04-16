import build.module_name as cam

def main():
    result = cam.python_sum_two_nums(10, 20)

    print(f"The result of python_sum_two_nums is: {result}")

    class_object = cam.PyClassName(5)

    print(class_object.multiply(3))

    list_mult = class_object.multiply_list([1, 2, 3, 4, 5])

    print(f"This: {list_mult} is type: {type(list_mult)}")

if __name__ == "__main__":
    main()