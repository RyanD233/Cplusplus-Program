# Cplusplus-Program

Q: Summarize the project and what problem it was solving.
A: This project was made for a fictional grocery store named Corner Grocer.  They wanted to know what items were being sold the most so they could update their layout to make shopping easier for their customers.  The store provided a text file that listed each item sold during a sample day for testing purposes.  The program runs through the file and inserts the names of the items as keys of a map if the item has not been seen yet, or it increments the value of that key for its count.  The user can then input numbers into a menu to find the count of a specific item, list the counts of all items, or show a histogram of each item and its count.

Q: What did you do particularly well?
A: I am proud of the limited lines that were needed in main.  It only included the creation of an object, 3 method calls, and the return statement.  This makes it easier to update and fix the code later because the code is seperated into methods rather than being a jumbled mess in the main function.  I also think that all of the user input was handled in a way that there would be no crashes.

Q: Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
A: I could have included non-case sensitive searching so the user could easily find items in the map.  I also could have included a way for the user to input the text file to read from.  This would allow the user to easily change what data they want to analyze as long as it follows the same structure as the sample text file.

Q: Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
A: The most challenging piece of code was the try catch() statement in the displayMenu() method because it deals with the input buffer.  Eventually, through forums on stack overflow, I figured out that I had to use clear() and ignore() to clear the buffer so that it would not keep inputting bad values.

Q: What skills from this project will be particularly transferable to other projects or course work?
A: I learned how to better deal with bad user input and reading and writing from files.  I believe these skills are needed in most projects.

Q: How did you make this program maintainable, readable, and adaptable?
A: To keep it maintainable and adaptable, I made sure to only include needed lines in the main() function.  Now, if a specific calculation or method is messing up or needs to be changed, the programmer knows where to look.  Otherwise, they would have to dig through the main() function to find what needs changed.  I made sure to include comments at the start of methods to give an idea of what it is doing, while also including comments on certain lines to give more context.
