class Addd:
    def __init__(self):
        self.Ezra = []


    def add(self):
        n=int(input("How many tasks do you want to add:"))
        
        for i in range(n):
                task = input("Enter the task: ")
                self.Ezra.append(task)
                print(f"Task {self.Ezra[i]} has been added to the List")


class Disp(Addd):
    def __init__ (self):
         super().__init__()
         
    
    def display(self):
        print("THE AVAILABLE TASKS:")
        if not self.Ezra:
            print("NO TASKS AVAILABLE:")
        else:
            for i in range(len(self.Ezra)):
                print(f"Tasks:\n {self.Ezra[i]}")


class Comp(Disp):
    def __init__ (self):
        super().__init__()
        
        
    def  complete(self):
        while True:
            if not self.Ezra:
                print("NO TASKS AVAILABLE:")
            else:
                for i in range(len(self.Ezra)):
                    ff = input(f"What task do you want to complete: {self.Ezra[i]}? ")
                    print(f"You chose to complete: {ff}")
        




m = Addd()
n = Disp()
b = Comp()



while True:
    result=int(input("What do you want to do:\n 1. Add a Task\n 2. Displat tasks\n 3. Complete a task\n 4.Exit\n"))

    if result==1:
        m.add()
    elif result==2:
        n.display()
    elif result==3:
        b.complete()
    elif result==4:
        break
    else:
        print("Not a Valid input!")
