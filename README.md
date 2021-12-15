# Class Design Part 2
In this project you will expand on the work from the previous project. Start with the work you submitted for _Class Design Part 1_ and make the additional changes requested below. You may create a new GitHub repository for this assignment, or you can use the same GitHub repository as you did for the previous project and make an additional _commit_ with the updates.

The changes below will require you to correctly apply _const-correctness_ and _reference semantics_ to your classes, as well as add some additional functionality.

## Project Requirements
Update *all* of your classes to enforce _const-correctness_. In particular should be able to call all _getter_ functions and _print_ functions with const objects.

Make the following adjustments for each section:

### Section A
Add a non-member output stream overload for your URL class which takes a const URL reference and prints out the URL information in the following format:
```
URL: https://example.com/
    SCHEME: https
    AUTHORITY: example.com
    PATH: /
```

### Section B
Change the external print function for the _image metadata_ object so that it is a proper non-member output stream overload that takes a const reference to an image metadata object. Just as before, the actual format of the data printed out is up to you and doesn't need to change from whatever you used in the last project.

### Section C
Add a non-member output stream overload to print a store item which takes an item by const reference. Make sure this function prints out all the data including the name, id, price, and quantity in stock.

Convert the function that prints a store information to a non-member output stream overload which takes a store by const reference.

Add a function called `processOrder` to the _store_ class that takes a const reference to an _order_ object. This function should remove all the items in the order from the store. For example, if I have a store with 5 books and 3 colored pencils and an order for 2 books and 1 colored pencil. The result of this function should be that the store now contains 3 books and 2 colored pencils.