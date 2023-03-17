
class TestDemo:
    def __init__(self):
        self.sess = 3
        print("类初始化成功")

    def evaluate(self, num):
        print("进入评估...")
        self.sess += num
        return self.sess, "评估结果"

class TestDemo2:
    def __init__(self, _age, _name):
        self.age = _age
        self.name = _name
        print('类初始化成功: %s\'s age is %d' %(self.name, self.age))

    def evaluate(self, grow):
        print("进入评估...")
        self.age += grow
        return self.age, self.name
    

# if __name__ == "__main__":
#   test = TestDemo2(15, "andy")
#   test.evaluate(5)