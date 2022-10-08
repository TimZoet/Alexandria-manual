Reference
=========

%TODO: References to same type.

Reference properties can be used to store references to instances of some other type. They can be added to a type using
the :code:`createReferenceProperty` and :code:`createReferenceArrayProperty` methods. Both these methods take a
reference to an already created type.

.. code-block:: cpp

    auto& foo   = library->createType("foo");
    auto& bar   = library->createType("bar");
    auto& prop0 = bar.createReferenceProperty("foo", foo);
    auto& prop1 = bar.createReferenceArrayProperty("foos", foo);

Single reference values are stored in the instance table as a single column value. More specifically, the identifier of
the referenced instance is stored. For arrays of references, a separate table is generated. This table has a column with
a reference to the instance table and a column with a reference to the referenced type. For each referenced instance in
the reference array, a row is added.
