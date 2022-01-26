#ifndef STORAGE_HPP
#define STORAGE_HPP

// Include header standard
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

namespace std {
	struct _Storage_Header {
		uint32_t id;
		size_t size;
	};

	class Storage {
		/* ------------ Variable ---------------*/
	private:
		uint32_t prLength = 0;
		uint32_t idNow = 0;
		size_t sizeNow = 0;
		char* data = (char*)malloc(sizeNow);

		/* ----- Constructor or Decontructor --- */
	public:
		Storage() = default;

		Storage(Storage& store) {
			prLength = store.prLength;
			idNow = store.idNow;
			sizeNow = store.sizeNow;
			data = store.data;
		}

		~Storage() {
			free(data);
		}

		/* ------------ add section ------------ */
	public:
		template<typename Type>
		inline void add(Type pData) {
			/* ------- Setup ------ */
			size_t nowSize = sizeNow;
			size_t size = sizeof(Type) + sizeof(struct _Storage_Header);
			sizeNow += size;
			data = (char*)realloc(data, sizeNow);

			/* ------- Make Header ------ */
			struct _Storage_Header storeHeader;
			storeHeader.id = this->idNow;
			storeHeader.size = sizeof(Type);

			/* ------- Convert into char* ------ */
			char* tHeader = (char*)&storeHeader;
			char* tData = (char*)&pData;

			/* ------- add header ------ */
			int size_s = sizeof(struct _Storage_Header);
			for (uint32_t i = nowSize; i < sizeof(struct _Storage_Header) + nowSize; i++) {
				data[i] = tHeader[i - nowSize];
			}

			/* ------- add data ------ */
			nowSize += size_s;
			for (uint32_t i = nowSize; i < sizeof(Type) + nowSize; i++) {
				data[i] = tData[i - nowSize];
			}
			nowSize += sizeof(Type);

			/* ------- Auto Increment ------ */
			idNow += 1;
			prLength += 1;
		}

		/* ------------ get section ------------ */
		template<typename Type>
		inline Type* get(int id) {
			uint32_t skip = 0;
			for (uint32_t i = 0; i < this->prLength; i++) {
				struct _Storage_Header* tStore = (struct _Storage_Header*)(data + skip);
				skip += sizeof(struct _Storage_Header);

				if (tStore->id == id) {
					break;
				}
				else {
					skip += tStore->size;
				}
			}
			return (Type*)(data + skip);
		}

		inline char* get() const {
			return data;
		}

		/* ------------ get section ------------ */
		inline uint32_t size() const {
			return prLength;
		}

		inline uint32_t sizes() const {
			return sizeNow;
		}

		/* ------------- remove section (TODO) --------- */
		inline void remove(uint32_t id) {
			// Setup
			size_t sizeTempMin = 0;
			uint32_t MX = 0;
			uint32_t skip = 0;

			// uint32_t size and position will be delete
			for (uint32_t i = 0; i < prLength; i++) {
				struct _Storage_Header* tStore = (struct _Storage_Header*)(data + skip);

				if (tStore->id == id) {
					MX = skip;
					sizeTempMin = tStore->size + sizeof(struct _Storage_Header);
				}

				skip += sizeof(struct _Storage_Header);
				skip += tStore->size;
			}

			// Setup temp
			char* tempData = (char*)malloc(skip - sizeTempMin);
			sizeNow -= sizeTempMin;

			// Copy
			uint32_t index = 0;
			for (uint32_t i = 0; i < skip; i++) {
				if (i == MX) {
					for (size_t j = 0; j < sizeTempMin; j++) {
						i += 1;
					}
				}

				tempData[index] = data[i];
				index += 1;
			}

			// Free and refrench
			free(data);
			data = tempData;

			// Set id
			prLength -= 1;
			idNow = 0;
			skip = 0;
			for (uint32_t i = 0; i < prLength; i++) {
				struct _Storage_Header* tStore = (struct _Storage_Header*)(data + skip);
				tStore->id = idNow;

				skip += sizeof(struct _Storage_Header);
				skip += tStore->size;
				idNow += 1;
			}
		}
	};
};

#endif // STORAGE_HPP