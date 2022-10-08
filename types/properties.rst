Properties
==========

.. toctree::
    :maxdepth: 3
    :titlesonly:
    :hidden:

    properties/primitive
    properties/string
    properties/blob
    properties/reference
    properties/nested

%TODO: Blob values and endianness/portability.

All types are automatically given a 64-bit signed integer property. This property is used as the instance identifier.
Internally, it is used as the primary key of the database table. Additionally, you can define any number of differently
typed properties, ranging from integers to raw binary data.

Just as with the type names, there are restrictions on property names. These are: %TODO: Forbidden property names.

The remaining subsections describe all supported property types. Section~\ref{section:classes} explains how to implement
C++ classes to match your type definitions.
