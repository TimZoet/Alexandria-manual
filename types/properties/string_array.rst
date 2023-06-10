String Array
============

String array properties can be used to store lists of string values. They can be added to a type layout using the
:code:`createStringArrayProperty` method.

.. code-block:: cpp

    alex::TypeLayout layout;
    alex::PropertyLayout& prop = layout.createStringArrayProperty("myprop");

Table Generation
----------------

For each string array property, a separate table is generated. Each element in an instance's string arrays is inserted
as a separate row containing a reference to the instance table and a value.

.. figure:: /_static/images/tables/string_array.svg

    Instance and string array table. Rows in the string array table reference a row from the instance table.

Class Definition
----------------

To handle arrays of string values, there is the :code:`alex::StringArray` class. This object holds a
:code:`std::vector<std::string>`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId  id;
        alex::StringArray strings;
    };

.. note:: 

    TODO: Implementing a custom class.
