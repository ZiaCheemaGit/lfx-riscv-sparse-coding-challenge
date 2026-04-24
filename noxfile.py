import nox

@nox.session()
def test_api(session):
    session.run("make", external=True)

    output = session.run("./run.o")
    output = session.run("./run.o", silent = True, external = True)

    assert "All tests passed! (100/100 iterations passed)" in output

