# Activity 8-1: User Roles

- When considering stories to implement, we must keep in mind our users.
- Users differ a lot from each other. They have different backgrounds/experiences/desires/needs.
- We *can* aggregate users into **user roles**.

    A user role is a collection of *defining attributes* that characterize a population of users and their *intended interactions* with the system.
- So user roles help us group our users together into groups that use the system in similar ways. When we think of adding functionality to a system, we do so to serve a particular role.
- Users might use a system for many different reasons and in many different ways. Therefore *a user may have many different user roles*.

When trying to find the user roles for our application, the standard process would consist of the following steps:

- *Brainstorm an initial set* of user roles. Everyone thinks of roles, crystalizes them in a short 1-2 word phrase, then writes it on an index card and places it on the wall. No discussion takes place during this phase.
- *Organize the initial set* by moving closer to each other roles that are similar. Users move cards around to have similar roles overlap with others.
- *Consolidate roles* by eliminating roles that are too similar to each other, or perhaps finding new names for these "super-roles". During this phase discussion happens between the authors of the various role cards. They describe what they have in mind with their name choice, and discuss how to consolidate roles. At the end of this process, we may still have roles that overlap with each other, and that is OK.
- *Refine the roles* by specifying the attributes that make each role distinct from the other roles (e.g. frequency of use, level of expertise in the domain, general technical proficiency etc). At this point notes may be added to the back of the card, to record these attributes.

## Grading Application Example

Let's revisit our running example of creating an application for managing student grades. Here are some examples of possible users:

- Joshua is a junior. He is going to be applying for summer internships soon, and he needs to be able to get a transcript record of all his classes.
- Kendra is a sophomore. She had a rough first year and is currently in probation. She regularly checks her grades for her courses this semester, as she needs to reach a certain GPA goal to avoid being dismissed.
- Ashley is a first year student. She had some problems with her schedule in the Fall with courses not showing up, so she now frequently checks her current class list to make sure she is registered for all the classes that she wanted to.
- Kevin is a Computer Science major. Keeping track of all the major requirements is quite tricky. Kevin wants to be able to find out what more he needs to do in order to complete his major and graduate. He also wants to keep track of his major GPA, as that determines some departmental honors that he is hoping to receive.
- Professor Smith is a Computer Science professor. Prof. Smith has had many problems with enrollments in his classes, so he uses the system to check his class rosters.
- Professor Ross is a Biology professor. She is the advisor for a large number of pre-med majors, and is particularly interested in being able to efficiently monitor their current courses as well as grades.
- Mr. Giver works in the registrar's office. He is responsible for adding new students into the system, and to handle any course add/drop requests that the students bring forward.
- Mrs. Swan also works in the registrar's office. She is responsible for making sure that rules are correctly implemented (e.g. are the requirements spelled out for someone's major correctly tracked?).
- Professor Lam is the Dean of Academic Affairs. He regularly needs information about average grades across all courses, as well as information about which classes are over-enrolled etc.

These are just some examples, to give you some idea of the diversity of users of the system.

Your task is as follows:

1. Brainstorming phase:
    - In groups of 4, come up with a list of user-roles; don't judge them or try to refine them, just generate as many as you can. Use a 2-3 word phrase for each. Write each role in a separate piece.
    - We come together and share our user-roles. Each group reads out their roles; other groups add cards for these extra roles to their piles, and can ask for clarification if they are not sure what the role represent.
2. Organization:
    - With all groups having the same set of roles, each group organizes these roles, by placing similar roles closer to each other.
    - We come together and each group discusses what they did. We come to some common agreement.
3. Consolidation:
    - Each group decides how to consolidate the roles into a smaller set of roles, by either eliminating roles or creating a new role out of existing roles.
    - We come together to discuss the choices.
4. Refinement:
    - With a common agreement on roles, each group adds to each role  the attributes that they think characterize that role.
    - We come together to discuss these attributes.
