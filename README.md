# Signup View Interview Question

Your task is to implement a signup form. The requirements are the following:

* There are 3 required fields:
  * username (2-15 characters)
  * email (must be a valid email address of the form x@y.z and must not be tim@kamcord.com)
  * password (6-30 characters)
* There is exactly one button on the form, which reads "Sign Up" and is initially disabled.
* All fields must be valid before the signup button becomes enabled. The class
  The class KCAccountValidator is provided for you which handles all validation
  logic. Note that some validation methods are asynchronous.
* Once all fields are valid, tapping the "Sign Up" button must dismiss the
  login view controller to reveal a simple view with a label that says "Hello,
  <username>", where <username> is the username that was entered in the signup
  form.

