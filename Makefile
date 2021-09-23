build:
	docker build -t findere .

run:
	docker run --rm -it --name findere findere

sh:
	docker exec -ti findere bash

clean:
	docker system prune -f --volumes