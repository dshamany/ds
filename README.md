# DS Utils

## Table of Content
- Description
- Usage
- Implementation
- Dependencies
- Future Plans

## Utilities Available
- dotenv

## Description

This is a C++ header-only implementation to be used wherever `.hpp` is allowed.

This `dotenv` utility enables a user to hide sensitive information in a .env file and easily retrieve the data. It is modeled after the NPM Package `dotenv`.

## Usage

**IMPORTANT!** Create a `.env` file in the same folder where your `main()` resides. Configuration must contain one key-value-pair on each line such as this: `KEY=VALUE` **WINTHOUT SPACES**.

If you wish to add this library to your system, the `include` header resides in the folder `ds` inside a nested folder `utils`. This is so that the `utils` folder does not clash with your other `include` headers.

At the top of your `main()`, declare `auto env = PROCESS::ENV::instance()` to instantiate the object. `PROCESS` is the main namespace here. `ENV()` is a singleton class implementation. You only have to instantiate it once at the beginning of your program.

To retrieve data, simply use `env.value(KEY_VALUE_STRING)` and set it to a variable. For instance, `auto var = env.value("KEY_VALUE_STRING")`.

You may also retrieve all variables with the `env.all()` function. This will enable you to loop over all the variables and retrieve them in a key-value-pair container (described below).

## Implementation

`PROCESS::ENV::instance()` is implemented in a Singleton fashion and will only need to be instantiated once as stated above.

`env.value(KEY_VALUE_STRING)` returns a `const std::string` variable for use.

`env.all()` is a function that returns a `std::map<std::string, std::string>` object. To access the variables internally, use the standard C++ pattern. For instance:

```
   for (auto& var : env.all()){
        std::cout << var.first << "=" << var.second << std::endl; 
    } 
```

As you can see, the example above demonstrates it's usage using a range for-loop.

## Dependencies

Any C++ compiler should do, provided it contains support for C++14. **No Third-Party Dependencies**.

## Testing

The header file was tested using both GCC and Clang compilers.

## Future Plans

As I develop C++ programs, I will build utilities to simplify the development process. The goal is that everything here should work in vanilla C++ and contain header only implementations. If the latter is not possible, I would recommend seeking other libraries to suit your requirements.

## Feedback

I would love to receive feedback, but will provide contact information when this small project is large enough to warrant such a requirement. No guarantees are made for the use of this header library.