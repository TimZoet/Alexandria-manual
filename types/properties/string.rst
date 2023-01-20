String
======

String properties can be used to store string values. They can be added to a type using the :code:`createStringProperty`
method.

.. code-block:: cpp

    auto& type   = nameSpace.createType("mytype");
    auto& string = type.createStringProperty("mystring");

Table Generation
----------------

String values are stored in the instance table as a single column value.

.. figure:: /_static/images/tables/string.svg

    Instance table. A single column is added per string property.

Class Definition
----------------

String properties do not require any extra care when defining classes. :code:`std::string` can be used directly.

.. code-block:: cpp

    struct Foo
    {
        alex::InstanceId id;
        std::string      s;
    };
