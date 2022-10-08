Primitive
=========

Primitive properties can be used to store integer and floating point values. They can be added to a type using the 
:code:`createPrimitiveProperty` method.

.. code-block:: cpp

    auto& type = library->createType("myType");
    auto& flt  = type.createPrimitiveProperty("prop0", alex::DataType::Float);
    auto& i32  = type.createPrimitiveProperty("prop1", alex::DataType::Int32);
    auto& i64  = type.createPrimitiveProperty("prop2", alex::DataType::Int64);

The :code:`setDefaultValue` method can be used to change the default value of each property.

.. code-block:: cpp

    flt.setDefaultValue(10.0f);
    i32.setDefaultValue(42);

Primitive values are stored in the instance table as a single column value. It is also possible to create arrays of
primitive values using the :code:`createPrimitiveArrayProperty`. These are stored in a separate table. This table has a
column with a reference to the instance table and a column with a primitive value. For each element of the primitive
array, a row is added.

.. code-block:: cpp

    auto& type   = library->createType("myType");
    auto& floats = type.createPrimitiveArrayProperty("prop", alex::DataType::Float);

While primitive arrays are useful, storing values in a separate table with a row for each value can be rather
inefficient for large arrays (where large is anything above a few dozen values). To solve this problem, there are
primitive blobs. These store arrays of primitive values as a contiguous binary object in the instance table.

.. code-block:: cpp

    auto& type = library->createType("myType");
    auto& ints = type.createPrimitiveBlobProperty("prop", alex::DataType::Int32);

Section~\ref{section:member_types:primitive_array} and Section~\ref{section:member_types:primitive_blob} describe the wrapper classes that manage primitive arrays and blobs.
