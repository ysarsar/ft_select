# ft_select
The goal of this project is to get you started on terminal manipulation with TERMCAPS. Here you will learn how to create a user interface for a program launched on the terminal.

## MANDATORY:

- [ ] Get the series of arguments, and displayed it in the terminal.
- [ ] The user move through the list of arguments using **arrows** (***the list is circular***).
- [ ] One or more options can be selected or un-selected with the **SPACE** key.
- [ ] With each selection the cursor position itself on the next element.
- [ ] The user validates the selection with the **RETURN** key, the list of choices will be sent back to shell separated by one space.
- [ ] Manage window resizing.
- [ ] If the user presses **ESC** key, the program musn’t send anything to the shell and it
has to exit properly.
- [ ] Manage **DELETING** ***elements from the list***
- [ ] **Choice non selected:** normal text.
- [ ] **Selected choice:** inverse video text.
- [ ] **Cursor’s position:** underlined text.
- [ ] **Selected choice + cursor’s position:** inverse video underlined text.
- [ ] At the end of the programme the default configuration of your terminal
**MUST** be restored.
- [ ] interept program with **ctrl+z** and restore it with **fg**.
- [ ] If the program is ***launched in an **empty** environment***, you need to behave reasonably.