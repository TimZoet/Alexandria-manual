String
======

String properties can be used to store single strings and arrays of strings. They can be added to a type using the
:code:`createStringProperty` and :code:`createStringArrayProperty` methods.

.. code-block:: cpp

    auto& type    = library->createType("myType");
    auto& string  = type.createStringProperty("s0");
    auto& strings = type.createStringArrayProperty("s1");

Single string values are stored in the instance table as a single column value. For arrays of strings, a separate table
is generated. This table has a column with a reference to the instance table and a column with a string value. For each
element of the string array, a row is added.

Section~\ref{section:member_types:string} and Section~\ref{section:member_types:string_array} describe the wrapper classes that manage string values and arrays.
