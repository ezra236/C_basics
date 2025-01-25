import getpass

class Ezra:
    adminpass = "123"  # Class attribute for admin password

    def __init__(self, adminpass):
        self.iscorrect = False
        self.adminpass = adminpass

    def validate(self, passw):
        attempts = 0
        while attempts < 2:
            if passw == self.adminpass:
                self.iscorrect = True
                return True
            else:
                print("Incorrect Password!")
                passw = getpass.getpass(prompt="Enter the password: ")
                attempts += 1
        return False

    def Quest(self, questNumber):
        if self.iscorrect:
            dictio = {
                1: "What is the capital of France?\n a) London\n b) Berlin\n c) Paris\n d) Madrid",
                2: "What is the largest planet in our solar system?\n a) Earth\n b) Jupiter\n c) Mars\n d) Venus",
                3: "Who wrote \"Romeo and Juliet\"?\n a) William Shakespeare\n b) Mark Twain\n c) Charles Dickens\n d) Jane Austen",
                4: "What is the chemical symbol for gold?\n a) Au\n b) Ag\n c) Fe\n d) Pb",
                5: "Which element has the atomic number 1?\n a) Helium\n b) Oxygen\n c) Hydrogen\n d) Carbon"
            }
            print(f"Question {questNumber}:")
            print(dictio.get(questNumber, "Invalid question number"))

class David(Ezra):
    def __init__(self, score):
        self.score = score

        super().__init__()
        self.Answ = {
            1: "Paris",
            2: "Jupiter",
            3: "William Shakespeare",
            4: "Au",
            5: "Hydrogen"
        }
        self.score = 0  

    def Answer(self, questNumber, user_answer):
        correct_answer = self.Answ.get(questNumber)
        if correct_answer:
            if user_answer.strip().lower() == correct_answer.lower():
                print("Correct!")
                self.score += 1  # Increment score for correct answer
            else:
                print(f"Incorrect. The correct answer is: {correct_answer}")
        else:
            print("Invalid question number")

    def calculate(self):
        return self.score  

# Main program
print("WELCOME TO The Quiz App")

password = getpass.getpass(prompt="Enter the password: ")

instance = Ezra()
instance1 = David()

if not instance.validate(password):
    print("Access denied.")
    exit()

for i in range(1, 6):
    instance.Quest(i)

    user_answer = input("Enter your answer: ")
    instance1.Answer(i, user_answer)

# Calculate and display score
score = instance1.calculate()
print(f"Your score: {score}/5")
