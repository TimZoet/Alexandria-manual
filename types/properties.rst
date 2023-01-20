Properties
==========

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    properties/instance_id
    properties/primitive
    properties/primitive_array
    properties/primitive_blob
    properties/string
    properties/string_array
    properties/blob
    properties/blob_array
    properties/reference
    properties/reference_array
    properties/nested

%TODO: Blob values and endianness/portability.

All types are automatically given a 64-bit signed integer property. This property is used as the instance identifier.
Internally, it is used as the primary key of the database table. Additionally, you can define any number of differently
typed properties, ranging from integers to raw binary data.

Just as with the type names, there are restrictions on property names. These are: %TODO: Forbidden property names.

The remaining subsections describe all supported property types. Section~\ref{section:classes} explains how to implement
C++ classes to match your type definitions.



In order to store and retrieve objects of a specific type the :code:`alex::ObjectHandler` class must be passed a C++
type and some additional information on how to match the class's member variables with specific properties. There are
some strict requirements on how to define such a class, although there is also a lot of freedom.

With the exception of primitive and string types, all member variables must be defined using special wrapper classes.

That being said, the order in which these member variables are defined, or even how they are structured is entirely up
to you. It is also perfectly legal to define member variables that do not correspond to any property. Furthermore, you
can define any number of classes and object handlers for a single type.
