Types
=====

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :hidden:

    types/namespaces
    types/properties
    types/type_descriptors

Let us pretend we are developing an appplication that keeps track of bicycles and the people that own them. The below
diagram shows the specification of our data types that we came up with. It's fairly straightforward. A person has a name
and owns zero or more bicycles. (We use an array for the owned bicycles so that our application can also be sold in the
Netherlands, where people often own more than one biycle.) A bicycle has two wheels, each of which has a radius and
width.

.. figure:: /_static/images/types.svg

    A language agnostic specification of our data types.

In order to translate this specification to C++ code, we need to go through several steps. First, we have to define a
namespace. All types need to be stored in one. More details can be found on the :doc:`/types/namespaces` page.

.. code-block:: cpp

    auto lib    = alex::Library::create("example.db");
    auto& main  = library->createNamespace("main");

With a namespace, we can start defining types and adding named properties to them. We can add primitive properties
(integers, floats) and string properties, as well as e.g. arrays of references. When done, we commit the types to
register them in the database and generate tables that will hold instances of these types. Full details can be found on
the :doc:`/types/properties` pages.

.. code-block:: cpp

    auto& wheel = main.createType("wheel", false);
    wheel.createPrimitiveProperty("radius", alex::DataType::Float);
    wheel.createPrimitiveProperty("width", alex::DataType::Float);

    auto& bicycle = main.createType("bicycle");
    bicycle.createNestedTypeProperty("front_wheel", wheel);
    bicycle.createNestedTypeProperty("back_wheel", wheel);

    auto& person = main.createType("person");
    person.createStringProperty("name");
    person.createReferenceArrayProperty("owned_bicycles", bicycle);

    wheel.commit();
    bicycle.commit();
    person.commit();

We also need to define some C++ classes that will correspond to our previously registered types. As you can see,
primitive properties are just primitive member variables in a class. Meanwhile, an array of references requires a
specific wrapper type. All these wrapper types are described on the same pages as their matching property.

.. code-block:: cpp

    struct Wheel
    {
        float radius = 0;
        float width  = 0;
    };

    struct Bicycle
    {
        alex::InstanceId id;
        Wheel            front;
        Wheel            back;
    };

    struct Person
    {
        alex::InstanceId              id;
        std::string                   name;
        alex::ReferenceArray<Bicycle> bicycles;
    };

Finally, we need to match the members of the classes with the types and their properties as we defined them previously.
This is done by defining :doc:`/types/type_descriptors`.

.. code-block:: cpp

    using WheelMemberList = alex::MemberList<alex::Member<&Wheel::radius>,
                                             alex::Member<&Wheel::width>>;

    using BicycleDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<&BicycleDescriptor::id>,
        alex::NestedMember<WheelMemberList, &BicycleDescriptor::front>,
        alex::NestedMember<WheelMemberList, &BicycleDescriptor::back>
    >;
    
    using PersonDescriptor = alex::GenerateTypeDescriptor<
        alex::Member<&Person::id>,
        alex::Member<&Person::bicycles>
    >;
    
    auto bicycleDesc = BicycleDescriptor(bicycle);
    auto personDesc = PersonDescriptor(person);

Once we have specified all these things, we can start running :doc:`/queries`.
