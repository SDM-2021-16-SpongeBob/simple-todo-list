# Functional specification

## Current situation

For contemporary college students, how to plan time is an important thing, and it is a good habit to use To-Do List to manage important things, things that need to be done, and things that have already been done.

We plan to write a software to manage the To-Do List!

We plan to develop the software step by step. We will provide a minimum viable product (MVP) first, and then we will add functions to the MVP and improve the user experience.

A one-stop solution for managing the important things, the things that need to be done, and the things that have already been done.

## Dream system / Wanted system





The software should have the following functions:

- Add To-Do task  (MVP)
- Delete To-Do task (MVP)
- Finish To-Do task  (MVP)
- Show the existing To-Do task (MVP)
- Provide help documentation  (MVP)
- Users register, login, log off
- Save the tasks in different txt files
- Countdown
- When the countdown is over, remind the user

## Current processes (model)

```txt
New task: User come up with a new task -> User take out the pen and notebook -> user write it down
```

## Required processes (model)

```txt
New task: User come up with a new task -> User log the tasks in the programe -> Save the tasks into a file
```

## Technology Stack Plans

We plan to build a command line application using C++.

## Interactive Design

### Add a To-Do task

```shell
stdl add <todo message>
```

It will return a `id` for this `<todo message>`.

### List To-Do tasks

```shell
stdl list
```

### Mark a To-Do task as done

```shell
stdl done <todo id>
```

### Delete a To-Do task

```shell
stdl del <todo id>
```

## Law, rules, standards

The users' privacy should be protected by login system

## Requirement list

- Gathering of software requirements and analysis of the project.
- Product design.
- Implementation/Coding.
- Testing.
- Deployment.
- Maintenance.

## Dictionary

- Name of the data item
- Aliases
- Description/purpose
- Related data items
- Range of values
- Data structure definition/Forms

## Use case

It outlines, from a user's point of view, a system's behavior as it responds to a request.

## ERD

![ERD](https://raw.githubusercontent.com/SDM-2021-16-SpongeBob/simple-todo-list/main/docs/images/ERD.png)

## Screen plans
