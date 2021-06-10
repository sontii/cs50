import cs50


text = cs50.get_string("Text: ")

letterCount = 0
wordCount = 1
sentenceCount = 0
index = 0  # get text length
grade = 0  # float grade
gradeLast = 0  # to round grade
lastIndex = 0  # catch (...) only one sentence sentence

sentence_end = {'?', '!', '.'}
word_end = {' '}

for i in range(len(text)):
    if (text[i].isalpha()):
        letterCount += 1
    elif (text[i] in sentence_end):
        sentenceCount += 1
    elif (text[i] in word_end):
        wordCount += 1

lw = (letterCount / wordCount)
sw = (sentenceCount / wordCount)


grade = (0.0588 * 100 * (letterCount / wordCount) - 0.296 * 100 * (sentenceCount / wordCount) - 15.8)

gradeLast = round(grade)  # round the grade

if gradeLast < 1:  # check grade
    print("Before Grade 1")
elif gradeLast >= 16:
    print("Grade 16+")
else:
    print(f"Grade {gradeLast}")