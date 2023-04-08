Table Sets
==========

.. toctree::
    :maxdepth: 1
    :titlesonly:
    :hidden:

    table_sets/instance
    table_sets/blob_array
    table_sets/primitive_array
    table_sets/reference_array

The :doc:`/queries/extended` barely scratch the surface of what is possible when it comes to writing complex queries.
They perform just a little bit of rerouting from properties to table columns. This is deliberate. Reinventing the wheel
is almost always a waste of time. In this case, writing yet another layer on top of the already existing, fully
functional, pure C++ SQLite API provided by the `cppql <https://github.com/TimZoet/cppql>`_ library would be quite
redundant.

To that end, the underlying tables of a type are exposed through the :code:`alex::TableSets` class. This class provides
objects representing all tables and columns that belong to that type. With these tables, arbitrary queries can be
created. An :code:`alex::TableSets` object can be constructed directly from an :code:`alex::TypeDescriptor`.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        float            a = 0.0f;
    };

    using FooDescriptor = alex::GenerateTypeDescriptor<alex::Member<"id", &Foo::id>,
                                                       alex::Member<"a", &Foo::a>>;
    
    auto fooDescriptor = FooDescriptor(...);
    auto fooTables     = alex::TableSets(fooDescriptor);

From a :code:`alex::TableSets` object, you can then retrieve tables and columns by index or by name, with the latter
probably being the best way to do it, since it will still work if you reorder properties. While the retrieval of tables
is described in the remainder of this section, writing queries is not covered in this manual. For that, refer to the
documentation of `cppql <https://github.com/TimZoet/cppql>`_.
