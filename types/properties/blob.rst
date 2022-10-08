Blob
====

Blob properties can be used to store arbitrary binary data. No explicit type information is maintained. This is entirely
the responsibility of the user. Note that the primitive blob property described in :doc:`/types/properties/primitive`
also stores binary data, but that property does store type information.

There are two types of blob properties: single and array. They can be added to a type using the
:code:`createBlobProperty` and :code:`createBlobArrayProperty` methods.

.. code-block:: cpp

    auto& type  = library->createType("myType");
    auto& prop0 = type.createBlobProperty("blob0");
    auto& prop1 = type.createBlobArrayProperty("blob1");

Single blob values are stored in the instance table as a single column value. For arrays of blobs, a separate table is
generated. This table has a column with a reference to the instance table and a column with a blob value. For each
element of the blob array, a row is added.

Section~\ref{section:member_types:blob} and Section~\ref{section:member_types:blob_array} describe the wrapper classes that manage blob values and arrays.
