# Contribution

The user should follow folloiwing rules while contributing.

1. Fork the repository.
2. Two files should be made one is `.hpp` and second one is `.cpp`.
3. The files you will write should work in both OS(*linux as well as windows*).You can make use of directives.
4. `.hpp` files will contain all the defination of the class and `.cpp` will contain the defination of the function of the class.
5. While creating class you should follow below pattern

    ```C++
    class <class_name>
    {
    private:
        // It will contain private variables.
    public:
        // It will contain public variables.
    private:
        // It will contain private functions
    public:
        // It will contain public functions

    };
    ```

6. At the top of the `.hpp` files you should write the name of the files and short description of the files.
7. Your `.hpp` files should not contain comments but you should write comments in `.cpp` files.(If possible in every line where necessary)
8. In addition to `.hpp` and `.cpp` files you have to make `.md` files to explaining how to use the class and its functions.
9. If are using any sort of the image then it must be kept inside resources folder.

10. The name of the image should be `<filename>-image_name`, filename is the name of README where it is used.
11. After you have written any `.hpp` and `.cpp` file donot forgot to add code in [main.cpp](/main.cpp) to demonstrate the class you have written.
12. Convention for naming:
    - All the constant name should be written in snake_case with all capital letter.
    - All the variable name should be written in snake_case with all small letter.
    - All the function name should be written in camelCase.
    - All the classs name should be written in PascalCase.
13. Also provide link to you `.md` file in the documention section of the repository [README](/README.MD) file.
14. And also mention the filenam which you have documented in the respective `.md` files.
15. Besure to keep the `.md` inside [documentation](/documentation/) folder.
16. Use **absolute url** in place of **relative url** while you are linking files in documentation.
17. Regarding commit, you must written commit in following manner.

    ```text
    <Title of the Commit>

    Short description of that commit

    ```

    **Example**:

    Suppose you have created a header file that allow image to display over the screen.

    ```text
    Display image over the screen

    ------.hpp will help to render the image over the screen. It support images like jpg, jpeg, png, etc.

    ```

    Additionally, you commit should give reader a brief knowledge of what you have done without seeing all those changes.

---

Dear contributer,

It may be boring reading those as everyone has their own way/tone of programming and this all may be burden for you all.
This all is done to bring only consistency. Moreover in near future we will be working with various company, people, etc
at that time they we need sync our coding style/tone with them to achieve maximum benefit.
So, think doing this actually we are learning and praticing sth that is related to our future.

Thank you.
