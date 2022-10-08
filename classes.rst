Defining Classes
================

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    classes/instance_id
    classes/primitive
    classes/primitive_array
    classes/primitive_blob
    classes/string
    classes/string_array
    classes/blob
    classes/blob_array
    classes/reference
    classes/reference_array

In order to store and retrieve objects of a specific type the :code:`alex::ObjectHandler` class must be passed a C++
type and some additional information on how to match the class's member variables with specific properties. There are
some strict requirements on how to define such a class, although there is also a lot of freedom.

With the exception of primitive and string types, all member variables must be defined using special wrapper classes.

That being said, the order in which these member variables are defined, or even how they are structured is entirely up
to you. It is also perfectly legal to define member variables that do not correspond to any property. Furthermore, you
can define any number of classes and object handlers for a single type.
